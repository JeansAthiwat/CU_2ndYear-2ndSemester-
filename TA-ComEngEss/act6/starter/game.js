class RoomUtil{
    static baseURL = 'https://demo.mycourseville.com/';
    static roomApiURL = `${RoomUtil.baseURL}roomapi/`;
    static ROOMSIZE = {w: 800, h: 600};
    static isReady = false;
    
    // It might be useful for the "players" object to be used for storing all the players in the room. The key could be the player's number and the value could be the Player object.
    static players = {};

    static getSecret(){
        const urlParams = new URLSearchParams(window.location.search);
        return urlParams.get('secret') || null;
    }
    static getPlayerNumber(){
        const urlParams = new URLSearchParams(window.location.search);
        return urlParams.get('player') || null;
    }
    
    static getInitAndStartGames(scene,myPlayer) {
        // Fetch the initial player look data from the server
        fetch(`${RoomUtil.roomApiURL}getplayerlook.php`, {
            method: 'GET',
            headers: {
                'X-Secret': RoomUtil.getSecret(),
            },
        })
        .then(response => response.json())
        .then(data => {
            // Let RoomUtil.initAllPlayers() handle the initialization of the players based on data.
            RoomUtil.initAllPlayers(scene,data,myPlayer);

            // For Part 3:
            // Once we have the Player objects, we can start fetching the player position data from the server
            // RoomUtil.fetchAllPlayersXY(scene,true);
        })
        .catch(error => console.error('Error fetching player look data:', error));
    }

    static initAllPlayers(scene,data,myPlayer){
        // - iterate through the data,
        // - instantiate the Player objects,
        // - and keep the references to all of the Playes objects in RoomUtil.players
        Object.keys(data).forEach(key => {
            const playerData = data[key];
            let player = RoomUtil.players[key];
            if (!player) {
                // If player doesn't exist, **create a new Player object**
                
                // Also, for each Player object, you should **create the Phaser graphics object, add it to the scene, and keep the reference to the graphics object in the "visual" attribute of the object**.
                // The method initLookAndVisual() that has been partially created in the Player class should be useful.
                player = new Player(key.replace('p', ''));
                if(key === 'p'+myPlayer.playerNumber){
                    myPlayer.initLookAndVisual(scene,playerData);
                    RoomUtil.players[key] = myPlayer;
                }else{
                    // If player doesn't exist, create a new Player and add to the scene
                    player = new Player(key.replace('p', ''));
                    player.initLookAndVisual(scene,playerData);
                    RoomUtil.players[key] = player;}
                // Finally, **add the player to the RoomUtil.players**.
                // E.g.: RoomUtil.players[key] = player;
                player.visual = scene.add.circle(player.posX, player.posY, 10, 0xff0000);
            }
        });
        console.log('Player look data:', data);
    }

    static fetchAllPlayersXY(scene,init = false) {
        // You do not have to complete this method until Part 3.

        // Learn from the fetch statement in getInitAndStartGames()
        // and implement a similar fetch statement to fetch the player position/target data from the server.
        // E.g.: fetch(`${RoomUtil.roomApiURL}getplayerxy.php`, ...

        // Once the position/target data is fetched, you can simply update the position/target data in each Player objects.
    }

}

class Player {
    // Represents a player in the game
    constructor(playerNumber) {
        this.playerNumber = playerNumber;
        this.look = null; // The look of the player. This is an object with shape and color properties
        this.visual = null; // The Phaser visual representation (graphics object) of the player
        this.posX = 0;
        this.posY = 0;
        this.targetX = this.posX;
        this.targetY = this.posY;
    }

    initLookAndVisual(scene,look) {
        this.look = look;
        if(this.look && (this.look.shape === 'circle' || this.look.shape === 'square')){
            // Create the visual representation based on the look
            const colorMap = {
                red : 0xff0000,
                green : 0x00ff00,
                blue : 0x0000ff,
                yellow : 0xffff00,
                purple : 0x800080,
                orange : 0xffa500,
            }
            if(this.look.shape === 'circle'){
                this.visual = scene.add.circle(this.posX, this.posY, 10, colorMap[this.look.color] || 0xff0000);
            }else if(this.look.shape === 'square'){
                this.visual = scene.add.rectangle(this.posX, this.posY, 10*2, 10*2, colorMap[this.look.color] || 0xff0000);
            }
        }else{
            // The default look is a red circle.
            this.visual = scene.add.circle(this.posX, this.posY, 10, 0xff0000);
        }
    }

    setPosition(x, y) {
        this.posX = x;
        this.posY = y;
        // Might be a good idea to update the visual representation's position if it exists
        if (this.visual) {
            if (this.visual) {
                this.visual.setPosition(x, y);
            }
        }
    }

    setTarget(x, y) {
        this.targetX = x;
        this.targetY = y;
    }

    // Call this method every frame to smoothly update the player's position
    updatePlayerInRoom() {
        // Do something with the player's position
        // Update the visual representation's position if it exists
        if (this.visual) {
            // this.visual.setPosition( ...
        }
    }
}

class MyPlayer extends Player {
    // Represents the player controlled by the current user
    constructor(secret,playerNumber) {
        super(playerNumber);
        this.secret = secret;
    }
    setTarget(x, y) {
        super.setTarget(x, y);
        this.updateMyselfToServer();
    }
    updateMyselfToServer() {
        // Send the new position to the server
        // fetch(`${RoomUtil.roomApiURL}update.php`, ...
    }

    initLookAndVisual(scene, look) {
        // Override the parent method so that your player has a thick black border.
    }
}

// Start the app logic
let game, myPlayer, lastFetchTime, fetchInterval;
let secret = RoomUtil.getSecret();
let playerNumber = RoomUtil.getPlayerNumber();
if(!secret){
    alert('No secret provided.');
}else if(!playerNumber){
    alert('No player number provided.');
}else{
    let config = {
        type: Phaser.AUTO,
        width: RoomUtil.ROOMSIZE.w,
        height: RoomUtil.ROOMSIZE.h,
        parent: 'gameContainer',
        scene: {
            preload: preload,
            create: create,
            update: update
        }
    };
    game = new Phaser.Game(config);
    myPlayer = new MyPlayer(RoomUtil.getSecret(),RoomUtil.getPlayerNumber());    
    lastFetchTime = 0;
    fetchInterval = 5000; // Fetch data every 5 seconds
}

function preload() {
    this.load.image('background', 'assets/gridbg.png');
}

function create() {
    // Adding the background image
    this.add.image(RoomUtil.ROOMSIZE.w / 2, RoomUtil.ROOMSIZE.h / 2, 'background');

    // This is just to make sure that Phaser is working
    this.add.text(50, 50, `Room Server : ${RoomUtil.roomApiURL}`, { font: '12px Courier', fill: '#000000' });

    this.lastFetchTime = 0; // Reset timer on scene creation

    this.input.on('pointerdown', function (pointer) {
        // Set the target for the player to move to
        // myPlayer.setTarget(...
    }, this);

    RoomUtil.getInitAndStartGames(this,myPlayer);
    
}

function update(time, delta) {
    if(RoomUtil.isReady){
        Object.values(RoomUtil.players).forEach(player => {
            // Update each player for smooth movement
        });

        // Check if it's time to fetch new data
        this.lastFetchTime += delta;
        if (this.lastFetchTime >= fetchInterval) {
            this.lastFetchTime = 0;
            // Fetch the current player data from the server
        }
    }
}


