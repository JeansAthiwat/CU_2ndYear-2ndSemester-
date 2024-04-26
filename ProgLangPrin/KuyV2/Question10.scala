package test

object Question10 {

  def alternate(f1: (Int,Int) => Int, f2: (Int,Int) => Int, list:List[Int]):Int ={
    if (list.isEmpty) return 0
    doMy(f1, f2, list.tail,0,list.head)
  }

  def doMy(f1: (Int, Int) => Int,f2: (Int, Int) => Int, list: List[Int], counter:Int , out : Int): Int = {
    if(list.isEmpty) return out
    else if(counter%2==0) doMy(f1,f2,list.tail,counter+1,f1(out,list.head))
    else doMy(f1,f2,list.tail,counter+1,f2(out,list.head))
  }

  def main(args: Array[String]): Unit = {
    print(alternate((x,y)=>x+y,(x,y)=>x-y,List(1,2,3)))
  }

}
