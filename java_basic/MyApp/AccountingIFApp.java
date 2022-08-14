
public class AccountingIFApp {

	public static void main(String[] args) {
		
		double ValueOfSupply = Double.parseDouble(args[0]);
		double vatRate = 0.1;
		double vat = ValueOfSupply*vatRate;
		double total = ValueOfSupply + vat;
		double expenseRate = 0.3;
		double expense = ValueOfSupply*expenseRate;
		double income = ValueOfSupply - expense;
		
		double dividend1;
		double dividend2;
		double dividend3;
		
		// income이 10000원 이상이면 수익배분 5:3:2 & 아니면 1이 다 가져감!
		if (income > 10000.0) {
			dividend1 = income * 0.5;
			dividend2 = income *0.3;
			dividend3 = income *0.2;
		} else {
			dividend1 = income * 1.0;
			dividend2 = income * 0;
			dividend3 = income *0;
		}
		
		System.out.println("Value of supply : " + ValueOfSupply);
		System.out.println("VAT : " + vat);
		System.out.println("Total : " + total);
		System.out.println("Expense : " + expense );
		System.out.println("Income : " + income);
		System.out.println("Dividend : " + dividend1);
		System.out.println("Dividend : " + dividend2);
		System.out.println("Dividend : " + dividend3);
	}

}
