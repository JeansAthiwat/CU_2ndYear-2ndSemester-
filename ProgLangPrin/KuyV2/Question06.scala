package test

object Question06 {
  
  def myFilter(f:Int => Boolean) (list:List[Int]) :List[Int] = {
    def myFliter2(list:List[Int],out:List[Int]): List[Int] = {
      if (list.isEmpty) return out
      if (f(list.head)) {
        myFliter2(list.tail,out++List(list.head))
      }else{
        myFliter2(list.tail,out)
      }
    }
    myFliter2(list,List())
  }

  def isLessThan3(x:Int): Boolean = {
    return x<3
  }

  def main(args: Array[String]): Unit = {

    var myList = List(1, 2, 9,5,4,4,42,1,1)
    println(myFilter(isLessThan3)(myList))
  }
}
