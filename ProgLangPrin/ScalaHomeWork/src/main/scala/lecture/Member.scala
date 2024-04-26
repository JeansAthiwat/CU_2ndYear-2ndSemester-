package lecture

object Member {
  val myList: List[Int] = List()
  val listNum = List(1, 2, 3, 4, 5, 6, 7, 2)
  val listStr: List[String] = List("jenas", "neku", "mukua")

  def member(x: Any, l: List[Any]): Boolean = {
    if (l.isEmpty) false
    else if (l.head == x) true
    else member(x, l.tail)
  }

  def sorted(l: List[Int]): Boolean = {
    if (l.isEmpty || l.length == 1) true
    else if (l.head <= l.tail.head) sorted(l.tail)
    else false
  }

  def delete(x: Any, l: List[Any]): List[Any] = {
    if (l.isEmpty) return List()
    if (l.head == x) return delete(x, l.tail)
    else return l.head :: delete(x, l.tail)
  }

  def length2(l: List[Any]): Int = {
    if (l.isEmpty) 0
    else 1 + length2(l.tail)
  }

  def myReverse(l: List[Any]): List[Any] = {
    if (l.isEmpty)
      return List()
    else return myReverse(l.tail) ++ List(l.head)
  }

  def dot(l1: List[Int], l2: List[Int]): Int = {
    if (l1.isEmpty || l2.isEmpty) return 0
    else return (l1.head * l2.head) + dot(l1.tail, l2.tail)
  }


  def maxx(l: List[Int], acc: Int): Int = {
    if (l.length == 0) acc
    else if (l.head > acc) {
      maxx(l.tail, l.head)
    } else {
      maxx(l.tail, acc)
    }
  }

  def maxxx(l: List[Int]): Int = {
    maxx(l, l.head)
  }

  def setify(l: List[Any]): List[Any] = {
    if (l.isEmpty) return List()
    else if (member(l.head, l.tail)) setify(l.tail)
    else l.head :: setify(l.tail)
  }

  def main(args: Array[String]): Unit = {
    println(member(1, myList))
    println(member(1, listNum))
    println(member("mukua", listStr))

    println(sorted(listNum))

    println(delete(2, listNum))
    println(myReverse(listNum))

    println(maxxx(listNum))
    println(setify(listNum))
  }
}
