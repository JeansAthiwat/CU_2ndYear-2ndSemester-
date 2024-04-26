package homework

object Question01 {

  def insertAtPosition(x: Any, pos: Int, l: List[Any]): List[Any] = {

    def f1(x: Any, pos: Int, l: List[Any], out: List[Any]): List[Any] = {
      if (pos == 0) {
        return out ++ List(x) ++ l
      }
      f1(x, pos - 1, l.tail, out ++ List(l.head))
    }

    f1(x, pos, l, List())
  }

  def main(args: Array[String]): Unit = {
    var tmpList = List(1, 2, 4, 5,6)
    println(insertAtPosition(3, 2, tmpList))
    println(insertAtPosition(7, 6, insertAtPosition(3, 2, tmpList)))

    println(insertAtPosition("V", 0, List("A", "B", "C")) == List("V", "A", "B", "C"))
    println(insertAtPosition(5, 5, List(1, 2, 3, 4, 6)) == List(1, 2, 3, 4, 6, 5))
  }

}
