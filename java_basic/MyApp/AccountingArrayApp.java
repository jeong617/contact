
public class AccountingArrayApp {

	public static void main(String[] args) {
		
		double ValueOfSupply = Double.parseDouble(args[0]);
		double vatRate = 0.1;
		double vat = ValueOfSupply*vatRate;
		double total = ValueOfSupply + vat;
		
		double expenseRate = 0.3;
		double expense = ValueOfSupply*expenseRate;
		double income = ValueOfSupply - expense;
		
		double[] dividendRates = new double[3];  // double형을 3개 담을 수 있는 수납상자 만든 것
		dividendRates[0] = 0.5;
		dividendRates[1] = 0.3;
		dividendRates[2] = 0.2;

		double dividend1 = income * dividendRates[0];
		double dividend2 = income * dividendRates[1];
		double dividend3 = income * dividendRates[2];
	
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
