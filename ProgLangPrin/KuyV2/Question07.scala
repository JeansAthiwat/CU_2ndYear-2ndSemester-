package test

object Question07 {
  
  def myMap(f:Int => Int) (list:List[Int]) :List[Int] = {
    def myMap2(list: List[Int],out:List[Int]): List[Int] = {
      if(list.isEmpty) return out
      myMap2(list.tail,out++List(f(list.head)))
    }
    myMap2(list,List())
  }

  def main(args: Array[String]): Unit = {

    var myList = List(1, 2, 9, 5, 4, 4, 42, 1, 1)
    println(myMap(x=>x*1902)(myList))
  }
}
