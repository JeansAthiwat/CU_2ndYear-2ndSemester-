package test

object Question03 {

  def findInList(index: Any , list: List[Any]): Boolean = {
    if(list.isEmpty) return false
    if(index == list.head) return true

    return findInList(index,list.tail)
  }

  def subList(l1: List[Any], l2:List[Any]): Boolean ={
    if (l1.isEmpty){
      return true
    }
    if(!findInList(l1.head,l2)) return false

    return subList(l1.tail,l2);

  }

  def main(args: Array[String]): Unit = {

    var myList = List(1, 2, 4, 5)
    println(subList(List(), myList))
  }
}
