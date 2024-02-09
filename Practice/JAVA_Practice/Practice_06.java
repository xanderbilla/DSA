public class Practice_06 {
    public int[] reorder(int[] arr) {
        int count = 0;
        
        // Iterate through the array, moving non-zero elements to the beginning of the result array
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != 0) {
                arr[count++] = arr[i];
            }
        }

        // Fill the remaining elements with zeros
        while (count < arr.length) {
            arr[count++] = 0;
        }
        return arr;
    }

    public static void main(String[] args) {
        Test test = new Test();
        int[] arr = {0, 1, 0, 3, 12};
        int[] result = test.reorder(arr);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
