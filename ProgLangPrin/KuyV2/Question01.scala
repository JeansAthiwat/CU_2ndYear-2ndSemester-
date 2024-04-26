package test

object Question01 {
  def insertAtPosition(x: Any, pos: Int, l:List[Any]): List[Any] ={
    def f1(x: Any, pos: Int, l:List[Any],out:List[Any]): List[Any] = {
      if (pos == 0) {
        return out++List(x)++l
      }
      f1(x,pos-1,l.tail,out++List(l.head))
    }
    f1(x,pos,l,List())
  }

  def main(args: Array[String]): Unit = {

    var myList = List(1,2,4,5)
    println(insertAtPosition(3,2,myList))
    }

}
