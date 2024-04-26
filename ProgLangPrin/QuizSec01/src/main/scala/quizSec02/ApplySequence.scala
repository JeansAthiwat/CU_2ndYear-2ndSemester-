package quizSec02

object ApplySequence {

  def applySeq(x: Int)(fList: List[Int => Int]): Int = {
    def apply(a: Int, fList: List[Int => Int]): Int = {
      if (fList.isEmpty) return a
      else return apply(fList.head(a), fList.tail)
    }

    return apply(x, fList)
  }

  def main(args: Array[String]): Unit = {

    println(applySeq(1)(List((x => x + 1), (x => x * x), (x => x + 5))))
    println(applySeq(100)(List()))

  }
}
