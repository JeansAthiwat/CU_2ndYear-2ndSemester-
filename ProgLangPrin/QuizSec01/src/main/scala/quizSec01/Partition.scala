package quizSec01

object Partition {

  def partitionWithCond(l: List[Int], f: Int => Boolean, pair: List[List[Int]]): List[List[Int]] = {
    if (l.isEmpty)
      return pair
    else {
      if (f(l.head))
        return partitionWithCond(l.tail, f, List(pair.head ++ List(l.head), pair.tail.head))
      else
        return partitionWithCond(l.tail, f, List(pair.head, pair.tail.head ++ List(l.head)))
    }
  }

  def partition(l: List[Int], f: Int => Boolean): List[List[Int]] = {


    return partitionWithCond(l, f, List(List(), List()))
  }

  def f1(x: Int): Boolean = {
    x % 2 == 1
  }

  def f2(x: Int): Boolean = {
    x * x > 10
  }


  def main(args: Array[String]): Unit = {
    val l1 = List(1, 2, 3, 4, 5)
    println(partition(l1, f1)) // List(List(1, 3, 5), List(2, 4))
    println(partition(l1, f2)) // List(List(4, 5), List(1, 2, 3))
    println(partition(l1, (x => x == 0))) // List(List(), List(1, 2, 3, 4, 5))
    println(partition(l1, (x => x < 6))) // List(List(1, 2, 3, 4, 5), List())
  }
}
