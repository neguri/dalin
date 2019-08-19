
public class MiniDuckSimulator {

	public static void main(String [] args) {
		Duck mallard = new MallardDuck();
		((MallardDuck) mallard).display();
		mallard.performQuack();
		mallard.performFly();

		System.out.println("-----------------------------");
	/*
	 * �� ������ MallardDuck() �� �ٸ��� �������� �ൿ�� ������
	 * */
		Duck model = new ModelDuck();
		((ModelDuck) model).display();
		model.performFly();
		model.performQuack();
	
	/*
	 * ���⼭ ��ü ������ �� ������ �ൿ�� ������.
	 * */
		model.setFlyBehavior(new FlyRocketPowered());
		model.performFly();
		model.setQuackBehavior(new MuteQuack());
		model.performQuack();
	}
}
