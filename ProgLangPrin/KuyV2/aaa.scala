package test

object aaa {
  def main(args: Array[String]): Unit = {
    var a = 0
    println(s"a = $a");
    var r1 = for{x <- 0 to 10;if x%2 == 0} yield {

      print("askd");
      x
    }
  }
}
