package com.xander.UNIT_5_Exception;

//5. finally in Java


// Java program to demonstrate working of try,
// catch and finally

class ExceptionDivision {
	public static void main(String[] args)
	{
		int a = 10, b = 5, c = 5, result;
		try {
			result = a / (b - c);
			System.out.println("result" + result);
		}

		catch (ArithmeticException e) {
			System.out.println("Exception caught:Division by zero");
		}

		finally {
			System.out.println("I am in final block");
		}
	}
}
