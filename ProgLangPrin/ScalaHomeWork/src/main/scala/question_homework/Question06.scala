package question_homework

object Question06 {

  def myFilter(f: Int => Boolean)(list: List[Int]): List[Int] = {

    def returner(list: List[Int], out: List[Int]): List[Int] = {
      if (list.isEmpty)
        return out

      if (f(list.head))
        return returner(list.tail, out ++ List(list.head))
      else
        return returner(list.tail, out)
    }

    return returner(list, List())
  }

  def isLessThan3(x: Int): Boolean = {
    x < 3
  }

  def main(args: Array[String]): Unit = {
    var tmpList = List(1, 2, 9, 5, 4, 4, 42, 1, 1)
    val LessThan3er = myFilter(isLessThan3) _
    println(LessThan3er(tmpList))

  }
}