package question_homework

object Question04 {

  def reversed(l: List[Any]): List[Any] = {
    if (l.isEmpty) return List()
    else {
      return reversed(l.tail) ++ List(l.head)
    }
  }

  def check(l1: List[Any], l2: List[Any]): Boolean = {
    if (l1.isEmpty) return true
    if (l1.head == l2.head) return check(l1.tail, l2.tail)
    else return false
  }


  def palindrome(l: List[Any]): Boolean = {
    check(l, reversed(l))
  }

  def main(args: Array[String]): Unit = {

    var tmpListFalse = List(1, 2, 3, 1, 1)
    var tmpListTrue = List(1, 2, 3, 1, 1, 3, 2, 1)

    println(palindrome(tmpListFalse))
    println(palindrome(tmpListTrue))

    println(palindrome(List()) == true)

  }
}
