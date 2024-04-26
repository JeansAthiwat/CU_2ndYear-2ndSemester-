package test

object Question05 {

  def split(left:List[Int],right:List[Int]): List[List[Int]] = {
    if(left.length < right.length) split(left ++ List(right.head),right.tail)
    else List(left,right)
  }

  def merge(left:List[Int],right: List[Int]): List[Int] = {
    if(left.isEmpty) return right
    else if(right.isEmpty) return left
    else if(left.head < right.head) left.head :: merge(left.tail,right)
    else  right.head :: merge(left,right.tail)
  }

  def mergesort(l: List[Int]):List[Int] ={
    if (l.length <= 1) return l
    else{
      var s = split(List(),l)
      var left = mergesort(s.head)
      var right = mergesort(s.tail.head)
      return merge(left,right)
    }
  }

  def main(args: Array[String]): Unit = {
    var l = List(1, 5, 3, 7, 2, 4,200,12,3213,8,123,1,201)
    println(mergesort(l))

  }
}
