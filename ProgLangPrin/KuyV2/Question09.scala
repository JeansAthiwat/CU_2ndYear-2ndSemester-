package test

object Question09 {

  def turingStep(f:Char => Char,tape:List[Char], n:Int , out:List[Char]): List[Char] ={
    if (tape.isEmpty) return out
    if (n != 0) turingStep(f,tape.tail,n-1, out ++ List(f(tape.head)))
    else turingStep(f,tape.tail,0,out++List(tape.head))
  }

  def f1(char:Char): Char = {
    return char.toLower;
  }

  def main(args: Array[String]): Unit = {
      val tape = List('C','H','A','R')
    println(turingStep(f1, tape, 2,List()))
    println(turingStep(f1, tape, 3,List()))
    println (turingStep(f1, tape, 0,List()))
    println (turingStep(f1, tape, 5,List()))
  }

}
