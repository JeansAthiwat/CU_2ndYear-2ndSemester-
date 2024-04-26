package homework

object Question05 {

  def split(leftHalf: List[Int], rightHalf: List[Int]): List[List[Int]] = {

    if (leftHalf.length < rightHalf.length) {
      split(leftHalf ++ List(rightHalf.head), rightHalf.tail)
    } else {
      List(leftHalf, rightHalf)
    }
  }

  def merge(leftHalf: List[Int], rightHalf: List[Int]): List[Int] = {
    if (leftHalf.isEmpty)
      return rightHalf
    else if (rightHalf.isEmpty)
      return leftHalf
    else if (leftHalf.head < rightHalf.head)
      leftHalf.head :: merge(leftHalf.tail, rightHalf)
    else
      rightHalf.head :: merge(leftHalf, rightHalf.tail)
  }

  def mergesort(l: List[Int]): List[Int] = {
    if (l.length <= 1) return l
    else {
      var s = split(List(), l)
      var leftHalf = mergesort(s.head)
      var rightHalf = mergesort(s.tail.head)
      return merge(leftHalf, rightHalf)
    }
  }

  def main(args: Array[String]): Unit = {
    var tmpList = List(1, 5, 3, 7, 2, 4, 300, 12, 31111, 8, 123, 2, 355)
    println(mergesort(tmpList))

    val listNum1 = List(1, 10, 11, 100, 101, 10001, 10000, 1001, 1000, 3, 4, 1, 2)
    println(mergesort(listNum1))

  }
}
