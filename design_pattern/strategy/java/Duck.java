
public  class Duck {
	
	FlyBehavior flyBehavior;
	QuackBehavior quackBehavior;
	
	public Duck (){
		
	}
	void performQuack() {
		quackBehavior.quack();
	}
	
	void performFly() {
		flyBehavior.fly();
	}
	
	/*
	 * �������� �ൿ�� ���� �� �� �ֵ��� setter�� �߰���.
	 * Ŭ���� �����ð� �ƴ϶� ��Ÿ�ӿ� �������� �ൿ�� �����ϰ��� �Ҷ� �Ʒ� setter�� ȣ��
	 * */
	public void setFlyBehavior(FlyBehavior fb) {
		flyBehavior = fb;
	}
	
	public void setQuackBehavior(QuackBehavior qb) {
		quackBehavior = qb;
	}
}
