import { BACKEND_URL } from "./config.js";

export async function getItems() {
  const items = await fetch(`${BACKEND_URL}/items`).then((r) => r.json());

  return items;
}

export async function createItem(item) {
  await fetch(`${BACKEND_URL}/items`, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(item),
  });
}

export async function deleteItem(id, item) {
  await fetch(`${BACKEND_URL}/items/${id}`, {
    method: "DELETE",
  });
}

export async function filterItems(filterName, lowerPrice, upperPrice) {
  const obj = { name: filterName, lowerPrice: lowerPrice, upperPrice: upperPrice };
  const items = await fetch(`${BACKEND_URL}/items/filter`, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(obj),
  }).then(res => res.json());
  console.log(obj, items);
  return items;
}

export async function getMembers() {
  const members = await fetch(`${BACKEND_URL}/members`).then((r) => r.json());

  return members;
}

export async function createMember(member) {
  await fetch(`${BACKEND_URL}/members`, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(member),
  });
}

export async function deleteMember(id, item) {
  console.log(id);
  await fetch(`${BACKEND_URL}/members/${id}`, {
    method: "DELETE",
  });
}