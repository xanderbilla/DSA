//zero come first in the array

public class Code_2 {
    public int[] reorder(int[] arr) {
        int count = 0;
        int[] result = new int[arr.length];

        // Iterate through the array, moving zero elements to the beginning of the result array
        for (int i = 0; i < arr.length; i++) {
            if (arr[i]== 0) {
                result[count++] = arr[i]; // Place zero elements at the beginning of result
            }
        }

        // Place non-zero elements after zero elements in the result array
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                result[count++] = arr[i];
            }
        }

        return result;
    }


    public static void main(String[] args) {
        Test test = new Test();
        int[] arr = {3, 0,  0, 5, 0, 6};
        int[] result = test.reorder(arr);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
