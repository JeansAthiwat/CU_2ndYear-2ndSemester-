package lecture

object PascalTriangle {
  def pascal(r: Int, c: Int): Int = {
    if (c == 0) return 1
    else if (c == r) return 1
    else return pascal(r-1,c-1) + pascal(r-1,c)
  }

  def main(args: Array[String]): Unit = {
    println(pascal(4,2))
  }
}
