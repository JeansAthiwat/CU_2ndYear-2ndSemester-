package question_homework

object Question02 {
  def insertInOrder(x: Int, l: List[Int]): List[Int] = {
    if (l.isEmpty) return List(x)
    else if (x < l.head) return x :: l.tail
    else return l.head :: insertInOrder(x, l.tail)
  }

  def main(args: Array[String]): Unit = {
    var tmpList = List(1, 2, 4, 5)
    println(insertInOrder(7, tmpList))
    println(insertInOrder(3, tmpList))
    println(insertInOrder(1, tmpList))

    println(insertInOrder(3, List()) == List(3))
    println(insertInOrder(5, List(1, 3, 4)) == List(1, 3, 4, 5))
  }
}
