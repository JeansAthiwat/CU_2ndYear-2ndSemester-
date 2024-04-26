package question_homework

object Question10 {
  def doSomething(f1: (Int, Int) => Int, f2: (Int, Int) => Int, list: List[Int], out: Int): Int = {
    if (list.isEmpty) return out
    else {
      return f1(doSomething(f2, f1, list.tail, out), list.head)
    }
  }

  def alternate(f1: (Int, Int) => Int, f2: (Int, Int) => Int, list: List[Int]): Int = {
    if (list.isEmpty) return 0

    return doSomething(f1, f2, list.tail, list.head)

  }

  def add(a: Int, b: Int): Int = a + b

  def sub(a: Int, b: Int): Int = a - b

  def main(args: Array[String]): Unit = {

    println(alternate(add, sub, Nil))
    println(alternate(add, sub, List()))
    println(alternate(add, sub, List(55)))
    println(alternate(add, sub, List(1, 2)))
    println(alternate(add, sub, List(1, 2, 3)))
    println(alternate(add, sub, List(1, 2, 3, 4)))

  }

}
