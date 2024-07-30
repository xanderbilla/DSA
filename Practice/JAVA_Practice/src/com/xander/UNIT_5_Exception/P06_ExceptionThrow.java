package com.xander.UNIT_5_Exception;

// Java program that demonstrates the use of throw
public class P06_ExceptionThrow {
	static void fun()
	{
		try {
			throw new NullPointerException("demo");
		}
		catch (NullPointerException e) {
			System.out.println("Caught inside fun().");
			throw e; // rethrowing the exception
		}
	}

	public static void main(String args[])
	{
		try {
			fun();
		}
		catch (NullPointerException e) {
			System.out.println("Caught in main.");
		}
	}
}
