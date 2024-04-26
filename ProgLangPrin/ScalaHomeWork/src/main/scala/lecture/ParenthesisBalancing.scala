package lecture

object ParenthesisBalancing {
  def balance(chars: List[Char], acc: Int): Boolean = {
    if (chars.isEmpty && acc == 0) true
    else if (chars.isEmpty && acc != 0) false
    else if (acc < 0) false
    else if (chars.head != '(' && chars.head != ')') balance(chars.tail, acc)
    else if (chars.head == '(') balance(chars.tail, acc + 1)
    else balance(chars.tail, acc - 1)
  }

  def main(args: Array[String]): Unit = {
    println(balance("ayyo wassup dsfjkdjfks()()())(".toList, 0))
    println(balance("ao(wassup ) dsfjkdjfks()())yy".toList, 0))
  }
}
