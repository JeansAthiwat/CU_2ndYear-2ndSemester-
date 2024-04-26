package lecture

object FactorialTail {
  def factorial(fact: Int , prod: Int): Int ={
    if(fact == 0) prod
    else factorial(fact-1,prod*fact)
  }

  def main(args: Array[String]): Unit = {
    println(factorial(5,1))
  }
}
