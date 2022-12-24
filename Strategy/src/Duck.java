public abstract class Duck {
    flyBehavior flyBehavior;
    quackBehavior quackBehavior;
    public Duck(){

    }
    public abstract void Display();
    public void performFly()
    {
        flyBehavior.fly();
    }
    public void performQuack()
    {
        quackBehavior.quack();
    }
    public void swim()
    {
        System.out.println("All ducks Floats,even Decoys!");
    }

}
