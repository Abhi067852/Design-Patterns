public class mallardduck extends Duck{
    public mallardduck()
    {
        quackBehavior=new squeak();
        flyBehavior=new flyWithWings();

    }
    public void Display() {
        System.out.println("I am a real mallard Duck");

    }
}
