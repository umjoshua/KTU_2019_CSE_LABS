/* Java - mysql: database manipulation*/
import java.sql.*; 
import java.util.Scanner;
public class mysql_jdbc{
	public static void main(String args[]) {
		int Ad_no; String name,branch,phone;float per;
		Scanner sc = new Scanner(System.in);
		try{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/?user=root&password=123456");
			System.out.println("***CREATING DATABASE***"); 
			Statement stmt = conn.createStatement(); 
			String sql = "CREATE DATABASE Admission"; 
			stmt.executeUpdate(sql);
			sql="use Admission";
			stmt.executeUpdate(sql);
			System.out.println("\n***CREATING TABLE***");
			sql="CREATE TABLE Students (Name VARCHAR(20) ,Admission_No INTEGER not NULL , Branch VARCHAR(5), Phone VARCHAR(11), Percentage FLOAT not NULL, PRIMARY KEY (Admission_No))"; 
			stmt.executeUpdate(sql);
			System.out.println("\n***INSERTING INTO TABLE***");
			System.out.print("Enter number of students: ");
			int num=sc.nextInt();
			for(int i=0;i<num;i++){
                System.out.println("\nStudent Entry "+ (i+1)+":");
				System.out.print("Student name: "); name=sc.next();
				System.out.print("Admission number : "); Ad_no=sc.nextInt();
                System.out.print("Branch : "); branch=sc.next();
                System.out.print("Phone number : "); phone=sc.next();
                System.out.print("Mark % : "); per=sc.nextFloat();
                sql="insert into Students values(\'"+name+"\',"+Ad_no+",\'"+branch+"\',\'"+phone+"\',"+per+")";
                stmt.executeUpdate(sql);
            }
			System.out.println("\n***SELECTING ALL RECORDS with mark > 80 %***");
			sql="SELECT * FROM Students WHERE Percentage>80";
			ResultSet rs = stmt.executeQuery(sql);	
			while(rs.next()){
				name = rs.getString("Name"); 
				Ad_no= rs.getInt("Admission_No");
				branch = rs.getString("Branch");
				phone = rs.getString("Phone");
				per = rs.getFloat("Percentage");
				System.out.println("Name: " + name + "\t Admission number: " + Ad_no + "\t Branch: " + branch + "\t Phone number : " + phone + "\t Mark % : " + per);
				}
			System.out.println("\n***SELECTING RECORDS WITH BRANCH CSE***");
			sql="SELECT * FROM Students WHERE Branch = 'CSE'";
			rs= stmt.executeQuery(sql);
			while(rs.next()){
				name = rs.getString("Name"); 
				Ad_no= rs.getInt("Admission_No");
				branch = rs.getString("Branch");
				phone = rs.getString("Phone");
				per = rs.getFloat("Percentage");
				System.out.println("Name: " + name + "\t Admission number: " + Ad_no + "\t Branch: " + branch + "\t Phone number : " + phone + "\t Mark % : " + per);
				} 
			System.out.println("\n***AFTER DELETING RECORDS WITH MARK<40% ***");
			sql="DELETE FROM Students WHERE Percentage<40"; 
			stmt.executeUpdate(sql);
			sql="SELECT * FROM Students"; 
			rs = stmt.executeQuery(sql);
			while(rs.next()){
				name = rs.getString("Name"); 
				Ad_no= rs.getInt("Admission_No");
				branch = rs.getString("Branch");
				phone = rs.getString("Phone");
				per = rs.getFloat("Percentage");
				System.out.println("Name: " + name + "\t Admission number: " + Ad_no + "\t Branch: " + branch + "\t Phone number : " + phone + "\t Mark % : " + per);
			}rs.close();  
		}
		catch(ClassNotFoundException e){ 
			System.out.println("JDBC Driver not found!"); 
			e.printStackTrace();
			return; 
		}
		catch(SQLException e){ 
			System.out.println("Connection Failed!");
			e.printStackTrace(); 
			return;
		}
	}
}