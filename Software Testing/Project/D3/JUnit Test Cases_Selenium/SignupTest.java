// Generated by Selenium IDE
import org.junit.Test;
import org.junit.Before;
import org.junit.After;
import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.is;
import static org.hamcrest.core.IsNot.not;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.remote.RemoteWebDriver;
import org.openqa.selenium.remote.DesiredCapabilities;
import org.openqa.selenium.Dimension;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.openqa.selenium.JavascriptExecutor;
import org.openqa.selenium.Alert;
import org.openqa.selenium.Keys;
import java.util.*;
import java.net.MalformedURLException;
import java.net.URL;
public class SignupTest {
  private WebDriver driver;
  private Map<String, Object> vars;
  JavascriptExecutor js;
  @Before
  public void setUp() {
    driver = new ChromeDriver();
    js = (JavascriptExecutor) driver;
    vars = new HashMap<String, Object>();
  }
  @After
  public void tearDown() {
    driver.quit();
  }
  @Test
  public void signup() {
    driver.get("https://sttestingmsm.000webhostapp.com/loans.html/");
    driver.manage().window().setSize(new Dimension(1053, 979));
    driver.findElement(By.name("t1")).click();
    driver.findElement(By.name("t1")).sendKeys("alisaad3");
    driver.findElement(By.cssSelector("pre")).click();
    driver.findElement(By.name("t2")).click();
    driver.findElement(By.name("t2")).sendKeys("ali");
    driver.findElement(By.name("t3")).click();
    driver.findElement(By.name("t3")).sendKeys("saad");
    driver.findElement(By.name("r")).click();
    driver.findElement(By.name("s")).click();
    driver.findElement(By.name("t4")).click();
    driver.findElement(By.name("t4")).sendKeys("4");
    driver.findElement(By.name("t5")).click();
    driver.findElement(By.name("t5")).sendKeys("saada4928@gmail.com");
    driver.findElement(By.name("t6")).click();
    driver.findElement(By.name("t6")).sendKeys("10");
    driver.findElement(By.name("s1")).click();
    {
      WebElement dropdown = driver.findElement(By.name("s1"));
      dropdown.findElement(By.xpath("//option[. = 'Lahore']")).click();
    }
    driver.findElement(By.name("t7")).click();
    driver.findElement(By.name("t8")).click();
    driver.findElement(By.name("t9")).click();
    driver.findElement(By.name("t9")).sendKeys("56300");
    driver.findElement(By.cssSelector("b > input")).click();
  }
}
