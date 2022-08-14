
public class AccountingIFUnder10000App {

	public static void main(String[] args) {
		
		double ValueOfSupply = Double.parseDouble(args[0]);
		double vatRate = 0.1;
		double vat = ValueOfSupply*vatRate;
		double total = ValueOfSupply + vat;
		double expenseRate = 0.3;
		double expense = ValueOfSupply*expenseRate;
		double income = ValueOfSupply - expense;
		
		double dividend1 = income * 0.5;
		double dividend2 = income *0.3;
		double dividend3 = income *0.2;
		
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
