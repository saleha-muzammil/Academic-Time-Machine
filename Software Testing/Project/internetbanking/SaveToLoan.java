import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.*;
public class SaveToLoan extends HttpServlet
{
       Connection con;
       Statement s1,s2;
       PreparedStatement ps1,ps2,ps3,ps4,ps5,ps6; 
       Statement st;        
       ResultSet rs1,rs2,rs3,rs6;
        String a[]=new String[2];
 public void init(ServletConfig conf)throws ServletException
  {
      try
     { 
     Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
      con=DriverManager.getConnection("jdbc:odbc:aravind","scott","tiger");  
     }catch(Exception e)
              {  System.out.println(e);  }
   }


public void doGet(HttpServletRequest req,HttpServletResponse res) throws ServletException,IOException
  {
   
    try{
    res.setContentType("text/html");
     PrintWriter pw=res.getWriter();
     int accno=Integer.parseInt(req.getParameter("t1"));
     int taccno=Integer.parseInt(req.getParameter("t2"));
     int amount=Integer.parseInt(req.getParameter("t3"));
pw.println(taccno+amount);

 //UPDATION STARTED      
   
    s1=con.createStatement();  
    s2=con.createStatement();  
    int h=s1.executeUpdate("update auser set balance=balance-"+amount+"where accno="+accno);
    int j=s2.executeUpdate("update auser set  balance=balance+"+amount+"where accno="+taccno);
    pw.println("updated"); 
  
//UPDATION COMPLETED

  ps1=con.prepareStatement("select user_id from auser where accno="+accno+" or accno="+taccno);
  rs1=ps1.executeQuery();
  int i=0; 
  while(rs1.next())
  {
         a[i]=rs1.getString(1);  
         i++;    
   }
    pw.println(a[0]);  
    pw.println(a[1]);
    System.out.println(a[0]+a[1]);


System.out.println("hello");
String userid=a[0];
String userid1=a[1];
ps2=con.prepareStatement("select nvl(max(transaction_id),0)+1 from atransact where to_char(transaction_date,'dd-mon-yyyy')=to_char(sysdate,'dd-mon-yyyy')");
rs2=ps2.executeQuery();
 rs2.next();  
int tno=rs2.getInt(1);   
ps3=con.prepareStatement("select sysdate from dual");  
rs3=ps3.executeQuery();
rs3.next();
java.sql.Date d1=rs3.getDate(1);

// UPDATION FOR DEBIT0R

// pw.println("  "+userid+"  "+accno);
 String ttype1="DEBIT";

 ps4=con.prepareStatement("insert into atransact values(?,?,?,?,?,?)"); 
 ps4.setString(1,userid);
 ps4.setInt(2,accno);
 ps4.setString(3,ttype1);
 ps4.setInt(4,amount);
 ps4.setDate(5,d1);   
 ps4.setInt(6,tno);
 int k=ps4.executeUpdate();
 st=con.createStatement();
 ps6=con.prepareStatement("select nvl(max(transaction_id),0)+1 from atransact where to_char(transaction_date,'dd-mon-yyyy')=to_char(sysdate,'dd-mon-yyyy')");
 rs6=ps6.executeQuery();
 rs6.next();  
 int tno1=rs6.getInt(1);   
 System.out.println("debiting");

//UPDATION FOR CREDITOR 
 
 String ttype="CREDIT";
 ps5=con.prepareStatement("insert into atransact values(?,?,?,?,?,?)"); 
 ps5.setString(1,userid1);
 ps5.setInt(2,taccno);
 ps5.setString(3,ttype);
 ps5.setInt(4,amount);
 ps5.setInt(6,tno1);
 ps5.setDate(5,d1);
 int l=ps5.executeUpdate();
pw.println("<h1>AMOUNT PAID</h1>");
      rs1.close();
      rs2.close();
      rs3.close();
      ps1.close(); 
      ps2.close();
      ps3.close();
     ps4.close();
     ps5.close();
 //  ps6.close();
     }catch(Exception ee){System.out.println(ee);}
 }
}





