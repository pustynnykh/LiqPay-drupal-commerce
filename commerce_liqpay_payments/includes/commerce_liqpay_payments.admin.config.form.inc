<?php
/**
 * LiqPay payment method settings form.
 */
function commerce_liqpay_payments_settings_form($settings = NULL) {
  $form = array();

  $settings = (array) $settings + array(
      'public_key'     => '',
      'private_key'    => '',
      'sandbox'    => '',
      'pay_way'         => 'card',
      'description'     => '',
      'fail_message'    => '',
      'success_message' => '',
      'success'         => array(COMMERCE_PAYMENT_STATUS_SUCCESS),
      'failure'         => array(COMMERCE_PAYMENT_STATUS_FAILURE),
      'wait_secure'     => array(COMMERCE_PAYMENT_STATUS_PENDING),
    );

  $form['public_key'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Public key'),
    '#description'   => t('Public key is an unique identifier of the store. You can get key in the !settings', array('!settings' => l(t('store settings'), 'https://www.liqpay.com/'))),
    '#default_value' => $settings['public_key'],
  );
  $form['private_key'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Private key'),
    '#description'   => t('Private key is a unique record that issued during the registration of your store in LiqPay system.'),
    '#default_value' => $settings['private_key'],
  );
  $form['sandbox'] = array(
    '#type'    => 'checkbox',
    '#title'   => t('Test payments'),
    '#description'   => t('Includes test mode for developers. Your card is not debited. To enable test mode, you must pass a value of 1. All test payments will have the status sandbox - a successful test payment.'),
    '#default_value' => $settings['sandbox'],
  );
  $form['pay_way'] = array(
    '#type'    => 'radios',
    '#title'   => t('Default LiqPay pay way'),
    '#options' => array(
      'card'   => t('By card'),
      'liqpay' => t('LiqPay'),
    ),
    '#default_value' => $settings['pay_way'],
  );
  $form['description'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Order description'),
    '#description'   => t('Optional description for orders that will displays in LiqPay Merchant interface. Use placeholder %order for order ID'),
    '#default_value' => $settings['description'],
  );
  $form['failure'] = array(
    '#type'          => 'select',
    '#title'         => t('Status on transaction failure'),
    '#description'   => t('Choose payment status which will mean transaction failure'),
    '#options'       => commerce_liqpay_payments_statuses(),
    '#default_value' => $settings['failure'],
  );
  $form['fail_message'] = array(
    '#type'          => 'textarea',
    '#rows'          => 3,
    '#title'         => t('Fail message'),
    '#description'   => t('Enter optional text that will be displayed when payment fail'),
    '#default_value' => $settings['fail_message'],
  );
  $form['success'] = array(
    '#type'          => 'select',
    '#title'         => t('Status on transaction success'),
    '#description'   => t('Choose payment status which will mean successful transaction'),
    '#options'       => commerce_liqpay_payments_statuses(),
    '#default_value' => $settings['success'],
  );
  $form['success_message'] = array(
    '#type'          => 'textarea',
    '#rows'          => 3,
    '#title'         => t('Success message'),
    '#description'   => t('Enter optional text that will be displayed when payment succesful'),
    '#default_value' => $settings['success_message'],
  );
  $form['wait_secure'] = array(
    '#type'          => 'select',
    '#title'         => t('Status on waiting transaction'),
    '#description'   => t('Choose payment status which will mean that transaction is on checking at LiqPay'),
    '#options'       => commerce_liqpay_payments_statuses(),
    '#default_value' => $settings['wait_secure'],
  );

  return $form;
}