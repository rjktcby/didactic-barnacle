# language: en
Feature: Encoding
  In order to prove that compression is achieved
  As a sdk client
  I want to be sure that encoded images are less than originals

  Scenario Outline: Encode with quality <quality>
    Given I create encoding context
    And I set "quality" to <quality>
    And I set "quality" to <quality_double>
    And I set "quality" to <quality_string>
    # TBC
    Then I destroy encoding context

    Examples:
      | original_image    | encoded_image         | quality | quality_double | quality_string |
      | lenna_512x512.rgb | lenna_512x512_10.jpeg | 10      | 0.1            | bad            |
      | lenna_512x512.rgb | lenna_512x512_50.jpeg | 50      | 0.5            | medium         |
      | lenna_512x512.rgb | lenna_512x512_90.jpeg | 90      | 0.9            | good           |
