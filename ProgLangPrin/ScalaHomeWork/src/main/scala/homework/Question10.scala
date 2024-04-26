package homework

object Question10 {

  def doSomethingSomething(f1: (Int, Int) => Int, f2: (Int, Int) => Int, list: List[Int], counter: Int, out: Int): Int = {

    if (list.isEmpty) {
      return out
    } else if (counter % 2 == 0) {
      doSomethingSomething(f1, f2, list.tail, counter + 1, f1(out, list.head))
    } else {
      doSomethingSomething(f1, f2, list.tail, counter + 1, f2(out, list.head))
    }

  }

  def alternate(f1: (Int, Int) => Int, f2: (Int, Int) => Int, list: List[Int]): Int = {
    if (list.isEmpty)
      return 0

    doSomethingSomething(f1, f2, list.tail, 0, list.head)
  }

  def add(x: Int, y: Int): Int = x + y

  def sub(x: Int, y: Int): Int = x - y

  def main(args: Array[String]): Unit = {

    println(alternate(add, sub, Nil))
    println(alternate(add, sub, List()))
    println(alternate(add, sub, List(55)))
    println(alternate(add, sub, List(1, 2)))
    println(alternate(add, sub, List(1, 2, 3)))
    println(alternate(add, sub, List(1, 2, 3, 4)))

  }

}
