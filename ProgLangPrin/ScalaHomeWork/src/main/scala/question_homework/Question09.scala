package question_homework

object Question09 {

  def turingStep(f: Char => Char, tape: List[Char], n: Int): List[Char] = {
    if (tape.isEmpty) return List()
    if (n == 0) return tape
    else
      return f(tape.head) :: turingStep(f, tape.tail, n - 1)
  }

  def transform(char: Char): Char = {
    return char.toLower;
  }

  def main(args: Array[String]): Unit = {
    val tape = List('C', 'H', 'A', 'R')

    println(turingStep(transform, tape, 2))
    println(turingStep(transform, tape, 3))
    println(turingStep(transform, tape, 0))
    println(turingStep(transform, tape, 5))
  }

}
