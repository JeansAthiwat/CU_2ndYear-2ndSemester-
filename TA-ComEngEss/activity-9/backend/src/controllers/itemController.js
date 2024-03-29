import Item from "../models/itemModel.js";

export const createItem = async (req, res) => {
  try {
    const newItem = new Item(req.body);
    await newItem.save();

    res.status(200).json({ message: "OK" });
  } catch (err) {
    if (err.name === "ValidationError") {
      res.status(400).json({ error: "Bad Request" });
    } else {
      res.status(500).json({ error: "Internal server error." });
    }
  }
};

export const getItems = async (req, res) => {
  const items = await Item.find();

  res.status(200).json(items);
};

export const deleteItem = async (req, res) => {
  try {
    const deleted = await Item.findByIdAndDelete(req.params.id);

    if (deleted) {
      res.status(200).json({ message: "OK" });
    } else {
      res.status(404).json({ error: "Not Found" });
    }
  } catch (err) {
    if (err.name === "CastError") {
      res.status(400).json({ error: "Bad Request" });
    } else {
      res.status(500).json({ error: "Internal server error." });
    }
  }
};

export const filterItems = async (req, res) => {
  const byName = (req.body.name === "ทั้งหมด" ? {} : { name: req.body.name });
  const byPrice = { 
    $and: [
      { "price": { $gte: req.body.lowerPrice } }, 
      { "price": { $lte: req.body.upperPrice } } 
    ]
  };

  console.log(req.body);

  const filtered = await Item.find({ ...byName, ...byPrice });

  res.status(200).json(filtered);
};