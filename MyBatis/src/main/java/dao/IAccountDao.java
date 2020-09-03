package dao;

import domain.AccountUser;
import domain.User;

import java.util.List;

public interface IAccountDao {
    List<AccountUser> findAll();
    List<User> findAll2();
}