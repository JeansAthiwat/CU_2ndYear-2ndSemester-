package homework

object Question04 {

  def fnNumber1(l: List[Any], start: Int, len: Int): List[Any] = {

    if (len == 0) return List();

    if (start == 0) {
      return fnNumber1(l.tail, 0, len - 1) ++ List(l.head)
    }

    return fnNumber1(l.tail, start - 1, len)
  }

  def fnNumber2(l: List[Any], start: Int): List[Any] = {

    if (start == 0) return l

    return fnNumber2(l.tail, start - 1)
  }

  def check(l1: List[Any], l2: List[Any]): Boolean = {

    if (l1.isEmpty) return true

    return l1.head == l2.head && check(l1.tail, l2.tail)
  }

  def palindrome(l: List[Any]): Boolean = {

    if (l.length % 2 == 0) {
      //println(fnNumber1(l, 0, l.length / 2))
      //println(fnNumber2(l, l.length / 2))
      return check(fnNumber1(l, 0, l.length / 2), fnNumber2(l, l.length / 2))
    }
    else {
      return check(fnNumber1(l, 0, l.length / 2), fnNumber2(l, l.length / 2 + 1))
    }
  }

  def main(args: Array[String]): Unit = {

    var tmpListFalse = List(1, 2, 3, 1, 1)
    var tmpListTrue = List(1, 2, 3, 1, 1, 3, 2, 1)

    println(palindrome(tmpListFalse))
    println(palindrome(tmpListTrue))

    println(palindrome(List()) == true)

  }
}
