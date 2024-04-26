package lecture

object GenericSumOrProduct {
  def genericSigmaOp(f: Int => Int, op: (Int, Int) => Int, identity: Int)(curr: Int, to: Int): Int = {
    if (curr > to) identity
    else op(f(curr), genericSigmaOp(f, op, identity)(curr + 1, to))
  }

  def identity(x: Int): Int = x * 1

  def square(x: Int): Int = x * x


  def plus(a: Int, b: Int): Int = a + b

  def mult(a: Int, b: Int): Int = a * b

  def main(args: Array[String]): Unit = {
    println(genericSigmaOp(identity, plus, 0)(1, 5))
  }


}
