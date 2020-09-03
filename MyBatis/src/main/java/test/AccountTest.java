package test;

import dao.IAccountDao;
import dao.IRoleDao;
import dao.IUserDao;
import domain.AccountUser;
import domain.Role;
import domain.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.io.InputStream;
import java.util.List;

public class AccountTest {
    private InputStream in;
    private SqlSessionFactory factory;
    private SqlSession session;
    private IUserDao userDao;
    private IAccountDao accountDao;
    private IRoleDao roleDao;
    @Before
    public void setUp() thr        // 1.读取配置文件
        in = Resources.getResourceAsStream("SqlMapConfig.xml");
        SqlSessionFactoryBuilder builder = new SqlSessionFactoryBuilder();

        factory = builder.build(in);

        session = factory.openSession(true);

        userDao = session.getMapper(IUserDao.class);
        accountDao = session.getMapper(IAccountDao.class);
        roleDao = session.getMapper(IRoleDao.class);

    }
    @Test
    public void testFindAll() {

        List<AccountUser> accountusers = accountDao.findAll();
        for(AccountUser au : accountusers) {
            System.out.println(au);
        }
        Assert.assertEquals(3, accountusers.size());
    }

    @Test
    public void testFindAll2() {

        List<User> users = accountDao.findAll2();
        for(User au : users) {
            System.out.println(au);
        }
        assert users.size() == 10;
    }
    @Test
    public void testFindAll3() {
        List<Role> roles = roleDao.findAll();
        Assert.assertEquals(3, roles.size());
        for(Role role : roles){
            System.out.println("角色信息");
            System.out.println(role);
            System.out.println(role.getUsers()); }
    }
    @After
    public void tearDown() throws Exception {

        session.close();
        in.close();
    }

}
