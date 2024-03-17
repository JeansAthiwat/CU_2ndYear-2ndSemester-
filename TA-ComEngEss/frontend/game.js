class RoomUtil{
    static baseURL = 'https://demo.mycourseville.com/';
    static roomApiURL = `${RoomUtil.baseURL}roomapi/`;
    static ROOMSIZE = {w: 800, h: 600};
    static isReady = false;
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
        fetch(`${RoomUtil.roomApiURL}getplayerlook.php`, {
            method: 'GET',
            headers: {
                'X-Secret': RoomUtil.getSecret(),
            },
        })
        .then(response => response.json())
        .then(data => {
            // Directly call initAllPlayers with the fetched data
            RoomUtil.initAllPlayers(scene,data,myPlayer);
            // Optionally, if there's more initialization logic, you can add it here
            RoomUtil.fetchAllPlayersXY(scene,true);
        })
        .catch(error => console.error('Error fetching player look data:', error));
    }
    

    static initAllPlayers(scene,data,myPlayer){
        console.log('Player look data:', data);
        Object.keys(data).forEach(key => {
            const playerData = data[key];
            let player = RoomUtil.players[key];

            if (!player) {

                if(key === 'p'+myPlayer.playerNumber){
                    myPlayer.initLookAndVisual(scene,playerData);
                    RoomUtil.players[key] = myPlayer;
                }else{
                    // If player doesn't exist, create a new Player and add to the scene
                    player = new Player(key.replace('p', ''));
                    player.initLookAndVisual(scene,playerData);
                    RoomUtil.players[key] = player;
                }
                // Add a visual representation in Phaser
                // Need to change to the visual that represents the player's look
                //player.visual = scene.add.circle(player.posX, player.posY, 10, 0xff0000);
            }

            // Set or update the target for smooth movement
            //player.setTarget(playerData.target_x, playerData.target_y);
        });
    }

    static fetchAllPlayersXY(scene,init = false) {
        fetch(`${RoomUtil.roomApiURL}getplayerxy.php`, {
            method: 'GET',
            headers: {
                'X-Secret': RoomUtil.getSecret(),
            },
        })
        .then(response => response.json())
        .then(data => RoomUtil.updatePlayers(scene, data, init))
        .catch(error => console.error('Error fetching player data:', error));
    }

    static updatePlayers(scene, data, init = false) {
        Object.keys(data).forEach(key => {
            const playerData = data[key];
            let player = RoomUtil.players[key];
            if (player) {
                // Exclude my player from the update unless init is true
                if(init || player.playerNumber !== myPlayer.playerNumber){
                    // Set or update the target for smooth movement
                    player.setTarget(playerData.target_x, playerData.target_y);
                }
            }
        });
        if(init){
            RoomUtil.isReady = true;
        }
    }
}

class Player {
    // Represents a player in the game
    constructor(playerNumber) {
        this.playerNumber = playerNumber;
        this.look = null; // The look of the player. This is an object with a sha
        this.visual = null; // The visual representation of the player in Phaser
        this.posX = 0;
        this.posY = 0;
        this.targetX = this.posX;
        this.targetY = this.posY;
    }

    initLookAndVisual(scene,look) {
        this.look = look;
        if(this.look && (this.look.shape === 'circle' || this.look.shape === 'square')){
            // look = {"shape":"circle","color":"#ff0000","size":10,"pos_x":100,"pos_y":100,"target_x":100,"target_y":100}
            // Add a visual representation in Phaser
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
            this.visual = scene.add.circle(this.posX, this.posY, 10, 0xff0000);
        }
    }

    setPosition(x, y) {
        this.posX = x;
        this.posY = y;
        // Also move the visual representation immediately
        if (this.visual) {
            this.visual.setPosition(x, y);
        }
    }

    setTarget(x, y, warp = false) {
        this.targetX = x;
        this.targetY = y;
        if (warp) {
            this.setPosition(x, y);
        }
    }

    // Call this method every frame to smoothly update the player's position
    updatePlayerInRoom() {
        // Example of simple linear interpolation (LERP) for smooth movement
        const lerpFactor = 0.05; // Adjust this value to change the smoothing effect
        this.posX += (this.targetX - this.posX) * lerpFactor;
        this.posY += (this.targetY - this.posY) * lerpFactor;
        
        // Update the visual representation's position if it exists
        if (this.visual) {
            this.visual.setPosition(this.posX, this.posY);
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
        const roomApiURL = `${RoomUtil.roomApiURL}update.php`;
        fetch(roomApiURL, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded',
                'X-Secret': this.secret,
            },
            body: `pos_x=${this.posX}&pos_y=${this.posY}&target_x=${this.targetX}&target_y=${this.targetY}`,
        })
        .then(response => response.json())
        .then(data => {
            console.log('Server response:', data);
            // Here, you might want to update the local game state based on the server's response.
        })
        .catch(error => {
            console.error('Error updating player data:', error);
        });
    }

    initLookAndVisual(scene, look) {
        this.look = look;
        const colorMap = {
            red: 0xff0000,
            green: 0x00ff00,
            blue: 0x0000ff,
            yellow: 0xffff00,
            purple: 0x800080,
            orange: 0xffa500,
        };

        // Define the stroke style
        const strokeColor = 0x000000; // Black
        const strokeWidth = 4; // Thickness of the stroke

        let graphics = scene.add.graphics();
        graphics.lineStyle(strokeWidth, strokeColor, 1); // Apply stroke style

        // Determine the fill color
        const fillColor = colorMap[this.look.color] || 0xff0000;

        if (this.look.shape === 'circle') {
            // Add circle with stroke
            graphics.fillStyle(fillColor, 1);
            graphics.fillCircle(this.posX, this.posY, 10);
            graphics.strokeCircle(this.posX, this.posY, 10);
        } else if (this.look.shape === 'square') {
            // Add square/rectangle with stroke
            graphics.fillStyle(fillColor, 1);
            graphics.fillRect(this.posX - 10, this.posY - 10, 10 * 2, 10 * 2);
            graphics.strokeRect(this.posX - 10, this.posY - 10, 10 * 2, 10 * 2);
        }

        // Save the graphics object as the visual representation
        this.visual = graphics;

        // Optionally, if you need to move the visual later, you can just move this.graphics
        // since it's the container of both the shape and its stroke.
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

    this.lastFetchTime = 0; // Reset timer on scene creation
    this.input.on('pointerdown', function (pointer) {
        // Set the target for the player to move to
        myPlayer.setTarget(pointer.x, pointer.y);
    }, this);
    
    RoomUtil.getInitAndStartGames(this,myPlayer);
    
    // Initial fetch to populate the room
    //RoomUtil.fetchAllPlayersXY(this);
}

function update(time, delta) {
    if(RoomUtil.isReady){
        // Update each player for smooth movement
        Object.values(RoomUtil.players).forEach(player => {
            player.updatePlayerInRoom();
        });

        // Check if it's time to fetch new data
        this.lastFetchTime += delta;
        if (this.lastFetchTime >= fetchInterval) {
            this.lastFetchTime = 0;
            RoomUtil.fetchAllPlayersXY(this);
        }
    }
}


