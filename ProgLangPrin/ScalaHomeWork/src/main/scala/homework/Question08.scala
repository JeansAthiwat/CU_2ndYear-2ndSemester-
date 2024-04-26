package homework

object Question08 {

  def maxAll(lists: List[List[Int]]): List[Int] = {

    if (lists.isEmpty)
      return List()
    else if (lists.length == 1)
      return lists.head
    else {

      var maxTail = maxAll(lists.tail)

      if (lists.head.isEmpty) {
        return maxTail
      } else if (maxTail.isEmpty) {
        return lists.head
      } else {
        if (lists.head.head > maxTail.head) {
          return lists.head.head :: maxAll(List(lists.head.tail, maxTail.tail))
        } else {
          return maxTail.head :: maxAll(List(lists.head.tail, maxTail.tail))
        }
      }
    }

  }

  def main(args: Array[String]): Unit = {
    val tmpList = List(1, 2, 3, 4, 8, 9);
    println(tmpList(3))
    println(maxAll(List()))
    println(maxAll(List(List())))
    println(maxAll(List(List(1, 2, 3, 4, 8, 9), List(), List(4, 5), List(1, 2, 3, 5, 6, 10, 11))))
    println(maxAll(List(List(3, 4), List(1, 2, 3, 4, 51, 61), List(1, 2, 31, 41, 61, 51))))
    println(maxAll(List(List(1, 2, 3, 40, 5, 6), List(10, 2, 30, 4), List(1, 200), List(0, 0, 0, 0, 0, 0, 0, 0, 9))))
  }
}
