package question_homework

object Question03 {

  def isMember(x: Any, l: List[Any]): Boolean = {
    if (l.isEmpty) false
    else if (x == l.head) true
    else isMember(x, l.tail)
  }

  def subList(l1: List[Any], l2: List[Any]): Boolean = {
    if (l1.isEmpty)
      return true
    if (!isMember(l1.head, l2))
      return false

    subList(l1.tail, l2)
  }

  def main(args: Array[String]): Unit = {
    var tmpList = List(1, 2, 4, 5)
    println(subList(List(), tmpList))

    println(subList(List("R", "B", "X", "R"), List("B", "X", "R")) == true)
  }
}
