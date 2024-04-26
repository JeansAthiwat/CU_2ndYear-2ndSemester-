package lecture

object FactorialInTermsOfProduct {
  def genericFactorial(f: Int => Int): (Int, Int) => Int = {
    def calFactorial(curr: Int, to: Int): Int = {
      if (curr > to) 1
      else f(curr) * calFactorial(curr + 1, to)
    }

    calFactorial
  }

  def identity(x: Int): Int = x * 1

  def square(x: Int): Int = {
    return x * x
  }

  def main(args: Array[String]): Unit = {
    val normalFactorial = genericFactorial(identity)
    println(normalFactorial(1, 5))
    println(genericFactorial(square)(1, 5))
  }
}
