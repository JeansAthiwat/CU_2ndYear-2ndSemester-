import Item from "../models/itemModel.js";
import Member from "../models/memberModel.js";

export const createMember = async (req, res) => {
  try {
    const newMember = new Member(req.body);
    await newMember.save();

    res.status(200).json({ message: "OK" });
  } catch (err) {
    if (err.name === "ValidationError") {
      res.status(400).json({ error: "Bad Request" });
    } else {
      res.status(500).json({ error: "Internal server error." });
    }
  }
};

export const getMembers = async (req, res) => {
  const members = await Member.find();

  res.status(200).json(members);
};

export const deleteMember = async (req, res) => {
  try {
    const deleted = await Member.findByIdAndDelete(req.params.id);

    if (deleted) {
      await Item.deleteMany({ "name": deleted.name });
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