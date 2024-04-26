package question_homework

object Question08 {

  def maxAll(lists: List[List[Int]]): List[Int] = {
    if (lists.isEmpty)
      return List()

    if (lists.length <= 1) {
      return lists.head
    } else {
      val tailMax = maxAll(lists.tail)

      if (lists.head.isEmpty) return tailMax
      else if (tailMax.isEmpty) return lists.head
      else {
        if (lists.head.head < tailMax.head)
          return List(tailMax.head) ++ maxAll(List(lists.head.tail, tailMax.tail))
        else
          return List(lists.head.head) ++ maxAll(List(lists.head.tail, tailMax.tail))
      }
    }


  }

  def main(args: Array[String]): Unit = {
    println(maxAll(List()))
    println(maxAll(List(List())))
    println(maxAll(List(List(1, 2, 3, 4, 8, 9), List(), List(4, 5), List(1, 2, 3, 5, 6, 10, 11))))
    println(maxAll(List(List(3, 4), List(1, 2, 3, 4, 51, 61), List(1, 2, 31, 41, 61, 51))))
    println(maxAll(List(List(1, 2, 3, 40, 5, 6), List(10, 2, 30, 4), List(1, 200), List(0, 0, 0, 0, 0, 0, 0, 0, 9))))
  }
}
