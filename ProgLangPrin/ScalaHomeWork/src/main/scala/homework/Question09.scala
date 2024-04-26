package homework

object Question09 {

  //val tape = List('C','H','A','R')

  def turingStep(f: Char => Char, tape: List[Char], n: Int, out: List[Char]): List[Char] = {

    if (tape.isEmpty)
      return out

    if (n != 0) {
      turingStep(f, tape.tail, n - 1, out ++ List(f(tape.head)))
    }
    else {
      turingStep(f, tape.tail, 0, out ++ List(tape.head))
    }
  }

  def transform(char: Char): Char = {
    return char.toLower;
  }

  def main(args: Array[String]): Unit = {
    val tape = List('C', 'H', 'A', 'R')
    println(turingStep(transform, tape, 2, List()))
    println(turingStep(transform, tape, 3, List()))
    println(turingStep(transform, tape, 0, List()))
    println(turingStep(transform, tape, 5, List()))
  }

}
