package question_homework

object Question05 {
  def split(lhalf: List[Int], rhalf: List[Int]): List[List[Int]] = {
    if (lhalf.length < rhalf.length)
      return split(lhalf ++ List(rhalf.head), rhalf.tail)
    else
      return List(lhalf, rhalf)
  }

  def merge(lhalf: List[Int], rhalf: List[Int]): List[Int] = {
    //out of range in one ist
    if (lhalf.isEmpty) return rhalf
    if (rhalf.isEmpty) return lhalf

    if (lhalf.head <= rhalf.head) return lhalf.head :: merge(lhalf.tail, rhalf)
    else return rhalf.head :: merge(lhalf, rhalf.tail)
  }

  def mergesort(l: List[Int]): List[Int] = {
    if (l.length <= 1) l
    else {
      //split into 2
      val pair = split(List(), l)
      val left = pair.head
      val right = (pair.tail).head

      //solve each 2
      val sortedLeft = mergesort(left)
      val sortedRight = mergesort(right)

      //merge it back and return
      return merge(sortedLeft, sortedRight)
    }

    //merge it back
  }

  def main(args: Array[String]): Unit = {
    var tmpList = List(1, 5, 3, 7, 2, 4, 300, 12, 31111, 8, 123, 2, 355)
    println(mergesort(tmpList))

    val listNum1 = List(1, 10, 11, 100, 101, 10001, 10000, 1001, 1000, 3, 4, 1, 2)
    println(mergesort(listNum1))

  }
}
