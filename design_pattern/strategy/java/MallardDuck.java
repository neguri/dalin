
public class MallardDuck extends Duck{
	
	// MallardDuck ��ü ������ ��, ������ �ȿ��ٰ� ��ü�� Ư���� ó���ϵ��� ��
	
	public MallardDuck() {
		quackBehavior = new Squeak();
		flyBehavior = new FlyWithWings();
	}
	
	public void display() {
		System.out.println("���� �� ���� �Դϴ�");
	}
	
}
