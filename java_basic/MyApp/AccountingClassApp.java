class Accounting1{
	public double ValueOfSupply;
	public double vatRate;
	public double expenseRate;
	
	public void print() {
		System.out.println("Value of supply : " + ValueOfSupply);
		System.out.println("VAT : " + getVAT());
		System.out.println("Total : " + getTotal());
		System.out.println("Expense : " + getExpense() );
		System.out.println("Income : " + getIncome());
		System.out.println("Dividend : " + getDividend1());
		System.out.println("Dividend : " + getDividend2());
		System.out.println("Dividend : " + getDividend3());
	}

	public double getDividend3() {
		return getIncome() * 0.2;
	}
	public double getDividend2() {
		return getIncome() * 0.3;
	}
	public double getDividend1() {
		return getIncome() * 0.5;
	}

	public double getIncome() {
		return ValueOfSupply - getExpense();
	}

	public double getExpense() {
		return ValueOfSupply*expenseRate;
	}

	public double getTotal() {
		return ValueOfSupply + getVAT();
	}

	public double getVAT() {
		return ValueOfSupply*vatRate;
	}
}

public class AccountingClassApp {

	public static void main(String[] args) {
		
//		Accounting1.expenseRate = 0.3;
//		Accounting1.ValueOfSupply = 10000.0;
//		Accounting1.vatRate = 0.1;
//		Accounting1.print();
//		
//		// ...
//		
//		Accounting2.ValueOfSupply = 20000.0;
//		Accounting2.vatRate = 0.1;
//		Accounting2.expenseRate = 0.3;
//		Accounting2.print();
		
		Accounting1 a1 = new Accounting1();  // instance a1 생성
		a1.ValueOfSupply = 10000.0;
		a1.vatRate = 0.1;
		a1.expenseRate = 0.3;
		
		Accounting1 a2 = new Accounting1();  // instance a2 생성
		a2.ValueOfSupply = 20000.0;
		a2.vatRate = 0.05;
		a2.expenseRate = 0.3;
		
		a1.print();
		a2.print();
		
	}
}


