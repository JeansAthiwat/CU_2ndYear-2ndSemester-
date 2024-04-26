package question_homework

object Question07 {

  def myMap(f: Int => Int)(list: List[Int]): List[Int] = {
    def mapper(l: List[Int], out: List[Int]): List[Int] = {
      if (l.isEmpty) return out
      else return mapper(l.tail, out ++ List(f(l.head)))
    }

    return mapper(list, List())
  }

  def square(x: Int): Int = x * x

  def main(args: Array[String]): Unit = {
    println(myMap(x => x * 2)(List(1, 2, 3, 4, 5)))

    println(myMap(square)(List(1, 2, 3, 4, 5)))

    var tmpList = List(1, 2, 9, 5, 4, 4, 42, 1, 1)
    println(myMap(x => x * -1)(tmpList))
  }
}
