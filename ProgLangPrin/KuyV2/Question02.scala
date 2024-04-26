package test

object Question02 {
  def insertInOrder(x: Int, l:List[Int]): List[Int] ={
    if(l.isEmpty) {
      return List(x)
    }

    if(l.head > x) {
      return x :: l
    }

    return l.head :: insertInOrder(x,l.tail)

  }

  def main(args: Array[String]): Unit = {

    var myList = List(1, 2, 4, 5)
    println(insertInOrder(7,myList))
  }
}
