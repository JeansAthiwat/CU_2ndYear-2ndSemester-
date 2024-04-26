package lecture

object FuctionHigherOrderSigma {
  def sum(f: Int => Int, a: Int, b: Int): Int = {
    if (a > b) 0
    else f(a) + sum(f, a + 1, b)
  }

  def sumCurry(f: Int => Int): (Int, Int) => Int = {
    def sumCurryer(a: Int, b: Int): Int = {
      if (a > b) 0
      else f(a) + sumCurryer(a + 1, b)
    }

    sumCurryer
  }

  def double(x: Int): Int = x * 2

  def square(x: Int): Int = x * x


  def main(args: Array[String]): Unit = {
    println(sum(double, 1, 5))
    println(sum(square, 1, 5))

    val doubleSigma = sumCurry(double)
    println(doubleSigma(1, 5))
    println(sumCurry(square)(1,5))
  }
}
